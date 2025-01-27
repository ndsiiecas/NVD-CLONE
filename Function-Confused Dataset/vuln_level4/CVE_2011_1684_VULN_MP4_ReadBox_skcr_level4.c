static int CVE_2011_1684_VULN_MP4_ReadBox_skcr( stream_t *p_stream, MP4_Box_t *p_box )
{
int origin_a, origin_aa[4];
    MP4_READBOX_ENTER( MP4_Box_data_frma_t );

    MP4_GET4BYTES( p_box->data.p_skcr->i_init );
    MP4_GET4BYTES( p_box->data.p_skcr->i_encr );
    MP4_GET4BYTES( p_box->data.p_skcr->i_decr );
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;

#ifdef MP4_VERBOSE
    msg_Dbg( p_stream, "read box: \"skcr\" i_init:%d i_encr:%d i_decr:%d",
             p_box->data.p_skcr->i_init,
             p_box->data.p_skcr->i_encr,
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
             p_box->data.p_skcr->i_decr );
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
#endif

    MP4_READBOX_EXIT( 1 );
}
