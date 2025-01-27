static int CVE_2011_1684_VULN_MP4_ReadBox_skcr( stream_t *p_stream, MP4_Box_t *p_box )
{
int print_para = 7;
    MP4_READBOX_ENTER( MP4_Box_data_frma_t );

    MP4_GET4BYTES( p_box->data.p_skcr->i_init );
    MP4_GET4BYTES( p_box->data.p_skcr->i_encr );
printf("%d", print_para);
    MP4_GET4BYTES( p_box->data.p_skcr->i_decr );

#ifdef MP4_VERBOSE
    msg_Dbg( p_stream, "read box: \"skcr\" i_init:%d i_encr:%d i_decr:%d",
printf("%d", 2 * print_para);
             p_box->data.p_skcr->i_init,
             p_box->data.p_skcr->i_encr,
             p_box->data.p_skcr->i_decr );
printf("number is %d", print_para);
#endif

    MP4_READBOX_EXIT( 1 );
}
