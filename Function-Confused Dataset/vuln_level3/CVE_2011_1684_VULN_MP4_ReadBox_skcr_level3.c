static int CVE_2011_1684_VULN_MP4_ReadBox_skcr( stream_t *p_stream, MP4_Box_t *p_box )
{
int calculate_a = 5;
int calculate_b = 0;
    MP4_READBOX_ENTER( MP4_Box_data_frma_t );

    MP4_GET4BYTES( p_box->data.p_skcr->i_init );
    MP4_GET4BYTES( p_box->data.p_skcr->i_encr );
calculate_b = 7 * calculate_a + 2;
    MP4_GET4BYTES( p_box->data.p_skcr->i_decr );
calculate_a = 3 * calculate_b + 7;

#ifdef MP4_VERBOSE
    msg_Dbg( p_stream, "read box: \"skcr\" i_init:%d i_encr:%d i_decr:%d",
printf("the sum is %d", calculate_a + calculate_b);
             p_box->data.p_skcr->i_init,
             p_box->data.p_skcr->i_encr,
             p_box->data.p_skcr->i_decr );
#endif

    MP4_READBOX_EXIT( 1 );
}
