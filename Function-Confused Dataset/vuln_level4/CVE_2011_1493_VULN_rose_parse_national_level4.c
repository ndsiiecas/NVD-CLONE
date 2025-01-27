static int CVE_2011_1493_VULN_rose_parse_national(unsigned char *p, struct rose_facilities_struct *facilities, int len)
{
int origin_a, origin_aa[4];
	unsigned char *pt;
	unsigned char l, lg, n = 0;
	int fac_national_digis_received = 0;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;

	do {
		switch (*p & 0xC0) {
		case 0x00:
			p   += 2;
			n   += 2;
			len -= 2;
			break;

		case 0x40:
			if (*p == FAC_NATIONAL_RAND)
				facilities->rand = ((p[1] << 8) & 0xFF00) + ((p[2] << 0) & 0x00FF);
			p   += 3;
			n   += 3;
			len -= 3;
			break;

		case 0x80:
			p   += 4;
			n   += 4;
			len -= 4;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
			break;

		case 0xC0:
			l = p[1];
			if (*p == FAC_NATIONAL_DEST_DIGI) {
				if (!fac_national_digis_received) {
					memcpy(&facilities->source_digis[0], p + 2, AX25_ADDR_LEN);
					facilities->source_ndigis = 1;
				}
			}
			else if (*p == FAC_NATIONAL_SRC_DIGI) {
				if (!fac_national_digis_received) {
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
					memcpy(&facilities->dest_digis[0], p + 2, AX25_ADDR_LEN);
					facilities->dest_ndigis = 1;
				}
			}
			else if (*p == FAC_NATIONAL_FAIL_CALL) {
				memcpy(&facilities->fail_call, p + 2, AX25_ADDR_LEN);
			}
			else if (*p == FAC_NATIONAL_FAIL_ADD) {
				memcpy(&facilities->fail_addr, p + 3, ROSE_ADDR_LEN);
			}
			else if (*p == FAC_NATIONAL_DIGIS) {
				fac_national_digis_received = 1;
				facilities->source_ndigis = 0;
				facilities->dest_ndigis   = 0;
				for (pt = p + 2, lg = 0 ; lg < l ; pt += AX25_ADDR_LEN, lg += AX25_ADDR_LEN) {
					if (pt[6] & AX25_HBIT)
						memcpy(&facilities->dest_digis[facilities->dest_ndigis++], pt, AX25_ADDR_LEN);
					else
						memcpy(&facilities->source_digis[facilities->source_ndigis++], pt, AX25_ADDR_LEN);
				}
			}
			p   += l + 2;
			n   += l + 2;
			len -= l + 2;
			break;
		}
	} while (*p != 0x00 && len > 0);

	return n;
}
