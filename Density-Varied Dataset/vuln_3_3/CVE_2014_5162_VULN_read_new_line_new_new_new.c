static gboolean
CVE_2014_5162_VULN_read_new_line(FILE_T fh, gint64 *offset, gint *length,
              gchar *linebuff, size_t linebuffsize, int *err, gchar **err_info)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
    /* Read in a line */
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
    gint64 pos_before = file_tell(fh);

if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
    if (file_gets(linebuff, (int)linebuffsize - 1, fh) == NULL) {
        /* No characters found, or error */
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
        *err = file_error(fh, err_info);
        return FALSE;
    }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }

    /* Set length (avoiding strlen()) and offset.. */
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
    *length = (gint)(file_tell(fh) - pos_before);
    *offset = *offset + *length;

    /* ...but don't want to include newline in line length */
    if (linebuff[*length-1] == '\n') {
        linebuff[*length-1] = '\0';
        *length = *length - 1;
    }
    /* Nor do we want '\r' (as will be written when log is created on windows) */
    if (linebuff[*length-1] == '\r') {
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
        linebuff[*length-1] = '\0';
if(judge_para * 5 > 8)  {printf("math exists!"); }
        *length = *length - 1;
    }

    return TRUE;
}
