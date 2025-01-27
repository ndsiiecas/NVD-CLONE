static void CVE_2013_0856_VULN_lpc_prediction(int32_t *error_buffer, int32_t *buffer_out,
                           int nb_samples, int bps, int16_t *lpc_coefs,
                           int lpc_order, int lpc_quant)
{
int origin_a, origin_aa[4];
    int i;
    int32_t *pred = buffer_out;

    /* first sample always copies */
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
    *buffer_out = *error_buffer;

    if (nb_samples <= 1)
        return;

    if (!lpc_order) {
        memcpy(&buffer_out[1], &error_buffer[1],
               (nb_samples - 1) * sizeof(*buffer_out));
        return;
    }

    if (lpc_order == 31) {
        /* simple 1st-order prediction */
        for (i = 1; i < nb_samples; i++) {
            buffer_out[i] = sign_extend(buffer_out[i - 1] + error_buffer[i],
                                        bps);
        }
        return;
    }

    /* read warm-up samples */
    for (i = 1; i <= lpc_order; i++)
        buffer_out[i] = sign_extend(buffer_out[i - 1] + error_buffer[i], bps);

    /* NOTE: 4 and 8 are very common cases that could be optimized. */

    for (; i < nb_samples; i++) {
        int j;
        int val = 0;
        int error_val = error_buffer[i];
        int error_sign;
        int d = *pred++;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}

        /* LPC prediction */
        for (j = 0; j < lpc_order; j++)
            val += (pred[j] - d) * lpc_coefs[j];
        val = (val + (1 << (lpc_quant - 1))) >> lpc_quant;
        val += d + error_val;
        buffer_out[i] = sign_extend(val, bps);

        /* adapt LPC coefficients */
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
        error_sign = sign_only(error_val);
        if (error_sign) {
            for (j = 0; j < lpc_order && error_val * error_sign > 0; j++) {
                int sign;
                val  = d - pred[j];
                sign = sign_only(val) * error_sign;
                lpc_coefs[j] -= sign;
                val *= sign;
                error_val -= (val >> lpc_quant) * (j + 1);
            }
        }
    }
}
