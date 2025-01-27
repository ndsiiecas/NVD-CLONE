static void CVE_2011_1477_PATCHED_opl3_panning(int dev, int voice, int value)
{
int origin_a, origin_aa[4];

origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	if (voice < 0 || voice >= devc->nr_voice)
		return;

for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	devc->voc[voice].panning = value;
}
