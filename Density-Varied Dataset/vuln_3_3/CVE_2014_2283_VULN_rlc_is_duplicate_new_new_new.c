static gboolean
CVE_2014_2283_VULN_rlc_is_duplicate(enum rlc_mode mode, packet_info *pinfo, guint16 seq,
		 guint32 *original)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
	GList              *element;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	struct rlc_seqlist  lookup, *list;
	struct rlc_seq      seq_item, *seq_new;

	rlc_channel_assign(&lookup.ch, mode, pinfo);
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	list = g_hash_table_lookup(sequence_table, &lookup.ch);
	if (!list) {
		/* we see this channel for the first time */
		list = se_alloc0(sizeof(*list));
		rlc_channel_assign(&list->ch, mode, pinfo);
		g_hash_table_insert(sequence_table, &list->ch, list);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	}
	seq_item.seq = seq;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	seq_item.frame_num = pinfo->fd->num;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }

if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	element = g_list_find_custom(list->list, &seq_item, rlc_cmp_seq);
	if (element) {
		seq_new = element->data;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
		if (seq_new->frame_num != seq_item.frame_num) {
			nstime_t delta;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
			nstime_delta(&delta, &pinfo->fd->abs_ts, &seq_new->arrival);
			if (delta.secs < RLC_RETRANSMISSION_TIMEOUT) {
				if (original)
					*original = seq_new->frame_num;
				return TRUE;
			}
			return FALSE;
if(judge_para * 5 > 8)  {printf("math exists!"); }
		}
		return FALSE; /* we revisit the seq that was already seen */
	}
	seq_new = se_alloc0(sizeof(struct rlc_seq));
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	*seq_new = seq_item;
	seq_new->arrival = pinfo->fd->abs_ts;
	list->list = g_list_insert_sorted(list->list, seq_new, rlc_cmp_seq);
	return FALSE;
}
