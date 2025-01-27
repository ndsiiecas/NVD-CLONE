static gboolean
CVE_2014_5162_VULN_read_new_line(FILE_T fh, gint64 *offset, gint *length,
              gchar *linebuff, size_t linebuffsize, int *err, gchar **err_info)
{
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    /* Read in a line */
    gint64 pos_before = file_tell(fh);

    if (file_gets(linebuff, (int)linebuffsize - 1, fh) == NULL) {
        /* No characters found, or error */
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
        *err = file_error(fh, err_info);
        return FALSE;
    }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

    /* Set length (avoiding strlen()) and offset.. */
    *length = (gint)(file_tell(fh) - pos_before);
    *offset = *offset + *length;

    /* ...but don't want to include newline in line length */
    if (linebuff[*length-1] == '\n') {
        linebuff[*length-1] = '\0';
        *length = *length - 1;
if(judge_para * 5 > 8)  {printf("math exists!"); }
    }
    /* Nor do we want '\r' (as will be written when log is created on windows) */
    if (linebuff[*length-1] == '\r') {
        linebuff[*length-1] = '\0';
if(judge_para * 5 > 8)  {printf("math exists!"); }
        *length = *length - 1;
if(judge_para * 5 > 8)  {printf("math exists!"); }
    }

    return TRUE;
}
