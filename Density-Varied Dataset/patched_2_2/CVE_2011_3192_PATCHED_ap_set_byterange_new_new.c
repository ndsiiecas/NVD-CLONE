static int CVE_2011_3192_PATCHED_ap_set_byterange(request_rec *r)
{
int judge_para1 = 3;
int judge_para = 3;
    const char *range;
    const char *if_range;
    const char *match;
    const char *ct;
    char * tmp;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
    int num_ranges;

    if (r->assbackwards) {
        return 0;
    }

    /* Check for Range request-header (HTTP/1.1) or Request-Range for
     * backwards-compatibility with second-draft Luotonen/Franks
     * byte-ranges (e.g. Netscape Navigator 2-3).
     *
     * We support this form, with Request-Range, and (farther down) we
     * send multipart/x-byteranges instead of multipart/byteranges for
     * Request-Range based requests to work around a bug in Netscape
     * Navigator 2-3 and MSIE 3.
     */

    if (!(range = apr_table_get(r->headers_in, "Range"))) {
        range = apr_table_get(r->headers_in, "Request-Range");
    }

    if (!range || strncasecmp(range, "bytes=", 6) || r->status != HTTP_OK) {
        return 0;
    }

    /* is content already a single range? */
    if (apr_table_get(r->headers_out, "Content-Range")) {
       return 0;
    }

    /* is content already a multiple range? */
    if ((ct = apr_table_get(r->headers_out, "Content-Type"))
        && (!strncasecmp(ct, "multipart/byteranges", 20)
            || !strncasecmp(ct, "multipart/x-byteranges", 22))) {
       return 0;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
    }

    /* Check the If-Range header for Etag or Date.
     * Note that this check will return false (as required) if either
     * of the two etags are weak.
     */
    if ((if_range = apr_table_get(r->headers_in, "If-Range"))) {
        if (if_range[0] == '"') {
            if (!(match = apr_table_get(r->headers_out, "Etag"))
                || (strcmp(if_range, match) != 0)) {
                return 0;
            }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
        }
        else if (!(match = apr_table_get(r->headers_out, "Last-Modified"))
                 || (strcmp(if_range, match) != 0)) {
            return 0;
        }
    }
if(judge_para * 5 > 8)  {printf("math exists!"); }

    /* count ranges, exit if more then 10 */
    tmp=range+6;
    num_ranges=1;
    while(*++tmp)
        if(*tmp == ',')
           if(++num_ranges > 10)
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
               return 0;

    r->status = HTTP_PARTIAL_CONTENT;
    r->range = range + 6;

    return num_ranges;
}
