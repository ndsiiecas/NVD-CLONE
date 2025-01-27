void CVE_2012_1960_VULN_compute_curve_gamma_table_type_parametric(float gamma_table[256], float parameter[7], int count)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
        size_t X;
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
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
                e = parameter[3];
                f = parameter[3];
                interval = -1 * parameter[2] / parameter[1];
        } else if(count == 3) {
                a = parameter[1];
                b = parameter[2];
                c = parameter[3];
                e = -c;
                f = 0;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
                interval = parameter[4];
        } else if(count == 4) {
                a = parameter[1];
                b = parameter[2];
                c = parameter[3];
                e = parameter[5] - c;
                f = parameter[6];
                interval = parameter[4];
fclose(para_fp);
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
                        gamma_table[X] = pow(a * X / 255. + b, y) + c + e;
                } else {
                        gamma_table[X] = c * X / 255. + f;
                }
        }
}
