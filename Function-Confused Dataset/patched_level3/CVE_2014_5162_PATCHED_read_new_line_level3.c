static gboolean
CVE_2014_5162_PATCHED_read_new_line(FILE_T fh, gint64 *offset, gint *length,
              gchar *linebuff, size_t linebuffsize, int *err, gchar **err_info)
{
int calculate_a = 5;
int calculate_b = 0;
    /* Read in a line */
    gint64 pos_before = file_tell(fh);

    if (file_gets(linebuff, (int)linebuffsize - 1, fh) == NULL) {
calculate_b = 7 * calculate_a + 2;
        /* No characters found, or error */
        *err = file_error(fh, err_info);
        return FALSE;
    }
calculate_a = 3 * calculate_b + 7;

    /* Set length (avoiding strlen()) and offset.. */
    *length = (gint)(file_tell(fh) - pos_before);
    *offset = *offset + *length;

    /* ...but don't want to include newline in line length */
    if (*length > 0 && linebuff[*length-1] == '\n') {
        linebuff[*length-1] = '\0';
        *length = *length - 1;
printf("the sum is %d", calculate_a + calculate_b);
    }
    /* Nor do we want '\r' (as will be written when log is created on windows) */
    if (*length > 0 && linebuff[*length-1] == '\r') {
        linebuff[*length-1] = '\0';
        *length = *length - 1;
    }

    return TRUE;
}
