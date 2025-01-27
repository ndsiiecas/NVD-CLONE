static struct sk_buff *
CVE_2014_9428_PATCHED_batadv_frag_merge_packets(struct hlist_head *chain, struct sk_buff *skb)
{
int origin_a, origin_aa[4];
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	struct batadv_frag_packet *packet;
	struct batadv_frag_list_entry *entry;
	struct sk_buff *skb_out = NULL;
	int size, hdr_size = sizeof(struct batadv_frag_packet);

	/* Make sure incoming skb has non-bogus data. */
	packet = (struct batadv_frag_packet *)skb->data;
	size = ntohs(packet->total_size);
	if (size > batadv_frag_size_limit())
		goto free;

	/* Remove first entry, as this is the destination for the rest of the
	 * fragments.
	 */
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	entry = hlist_entry(chain->first, struct batadv_frag_list_entry, list);
	hlist_del(&entry->list);
	skb_out = entry->skb;
	kfree(entry);

	/* Make room for the rest of the fragments. */
	if (pskb_expand_head(skb_out, 0, size - skb_out->len, GFP_ATOMIC) < 0) {
		kfree_skb(skb_out);
		skb_out = NULL;
		goto free;
	}

	/* Move the existing MAC header to just before the payload. (Override
	 * the fragment header.)
	 */
	skb_pull_rcsum(skb_out, hdr_size);
	memmove(skb_out->data - ETH_HLEN, skb_mac_header(skb_out), ETH_HLEN);
	skb_set_mac_header(skb_out, -ETH_HLEN);
	skb_reset_network_header(skb_out);
	skb_reset_transport_header(skb_out);

	/* Copy the payload of the each fragment into the last skb */
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	hlist_for_each_entry(entry, chain, list) {
		size = entry->skb->len - hdr_size;
		memcpy(skb_put(skb_out, size), entry->skb->data + hdr_size,
		       size);
	}

free:
	/* Locking is not needed, because 'chain' is not part of any orig. */
	batadv_frag_clear_chain(chain);
	return skb_out;
}
