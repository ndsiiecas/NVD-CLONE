static uint8_t *CVE_2013_0878_VULN_advance_line(uint8_t *start, uint8_t *line,
                             int stride, int *y, int h, int interleave)
{
int origin_a, origin_aa[4];
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
    *y += interleave;

for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
    if (*y < h) {
        return line + interleave * stride;
    } else {
        *y = (*y + 1) & (interleave - 1);
        if (*y) {
            return start + *y * stride;
        } else {
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
            return NULL;
        }
    }
}
