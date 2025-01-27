static int CVE_2011_1684_VULN_MP4_ReadBox_skcr( stream_t *p_stream, MP4_Box_t *p_box )
{
int judge_para = 3;
    MP4_READBOX_ENTER( MP4_Box_data_frma_t );

    MP4_GET4BYTES( p_box->data.p_skcr->i_init );
    MP4_GET4BYTES( p_box->data.p_skcr->i_encr );
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    MP4_GET4BYTES( p_box->data.p_skcr->i_decr );
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
#ifdef MP4_VERBOSE
    msg_Dbg( p_stream, "read box: \"skcr\" i_init:%d i_encr:%d i_decr:%d",
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
             p_box->data.p_skcr->i_init,
             p_box->data.p_skcr->i_encr,
             p_box->data.p_skcr->i_decr );
if(judge_para * 5 > 8)  {printf("math exists!"); }
#endif

    MP4_READBOX_EXIT( 1 );
}
