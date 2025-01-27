static int CVE_2011_1684_PATCHED_MP4_ReadBox_skcr( stream_t *p_stream, MP4_Box_t *p_box )
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    MP4_READBOX_ENTER( MP4_Box_data_skcr_t );

    MP4_GET4BYTES( p_box->data.p_skcr->i_init );
    MP4_GET4BYTES( p_box->data.p_skcr->i_encr );
    MP4_GET4BYTES( p_box->data.p_skcr->i_decr );

gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
#ifdef MP4_VERBOSE
    msg_Dbg( p_stream, "read box: \"skcr\" i_init:%d i_encr:%d i_decr:%d",
             p_box->data.p_skcr->i_init,
             p_box->data.p_skcr->i_encr,
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
             p_box->data.p_skcr->i_decr );
#endif

fclose(para_fp);
    MP4_READBOX_EXIT( 1 );
}
