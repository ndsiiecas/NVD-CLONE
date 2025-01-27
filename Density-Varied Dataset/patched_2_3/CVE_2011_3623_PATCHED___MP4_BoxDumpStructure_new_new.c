static void CVE_2011_3623_PATCHED___MP4_BoxDumpStructure( stream_t *s,
                                    MP4_Box_t *p_box, unsigned int i_level )
{
int judge_para1 = 3;
int judge_para = 3;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
    MP4_Box_t *p_child;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    if( !i_level )
    {
        if MP4_BOX_TYPE_ASCII()
            msg_Dbg( s, "dumping root Box \"%4.4s\"",
                              (char*)&p_box->i_type );
        else
            msg_Dbg( s, "dumping root Box \"c%3.3s\"",
                              (char*)&p_box->i_type+1 );
    }
    else
    {
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
        unsigned int i;

        char str[512];
        if( i_level * 5 + 1 >= sizeof(str) )
            return;

        memset( str, ' ', sizeof(str) );
        for( i = 0; i < i_level; i++ )
        {
            str[i*5] = '|';
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
        }
        if( MP4_BOX_TYPE_ASCII() )
            snprintf( &str[i_level * 5], sizeof(str) - 5*i_level,
                      "+ %4.4s size %d",
                        (char*)&p_box->i_type, (uint32_t)p_box->i_size );
        else
            snprintf( &str[i_level * 5], sizeof(str) - 5*i_level,
                      "+ c%3.3s size %d",
                        (char*)&p_box->i_type+1, (uint32_t)p_box->i_size );
if(judge_para * 5 > 8)  {printf("math exists!"); }
        msg_Dbg( s, "%s", str );
    }
    p_child = p_box->p_first;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    while( p_child )
    {
        CVE_2011_3623_PATCHED___MP4_BoxDumpStructure( s, p_child, i_level + 1 );
        p_child = p_child->p_next;
    }
}
