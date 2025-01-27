void CVE_2012_1960_PATCHED_compute_curve_gamma_table_type_parametric(float gamma_table[256], float parameter[7], int count)
{
int origin_a, origin_aa[4];
        size_t X;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
        float interval;
        float a, b, c, e, f;
        float y = parameter[0];
        if (count == 0) {
                a = 1;
                b = 0;
                c = 0;
                e = 0;
                f = 0;
                interval = -INFINITY;
        } else if(count == 1) {
                a = parameter[1];
                b = parameter[2];
                c = 0;
                e = 0;
                f = 0;
                interval = -1 * parameter[2] / parameter[1];
        } else if(count == 2) {
                a = parameter[1];
                b = parameter[2];
                c = 0;
                e = parameter[3];
                f = parameter[3];
                interval = -1 * parameter[2] / parameter[1];
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
        } else if(count == 3) {
                a = parameter[1];
                b = parameter[2];
                c = parameter[3];
                e = -c;
                f = 0;
                interval = parameter[4];
        } else if(count == 4) {
                a = parameter[1];
                b = parameter[2];
                c = parameter[3];
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
                e = parameter[5] - c;
                f = parameter[6];
                interval = parameter[4];
        } else {
                assert(0 && "invalid parametric function type.");
                a = 1;
                b = 0;
                c = 0;
                e = 0;
                f = 0;
                interval = -INFINITY;
        }       
        for (X = 0; X < 256; X++) {
                if (X >= interval) {
                        // XXX The equations are not exactly as definied in the spec but are
                        //     algebraic equivilent.
                        // TODO Should division by 255 be for the whole expression.
                        gamma_table[X] = clamp_float(pow(a * X / 255. + b, y) + c + e);
                } else {
                        gamma_table[X] = clamp_float(c * X / 255. + f);
                }
        }
}
