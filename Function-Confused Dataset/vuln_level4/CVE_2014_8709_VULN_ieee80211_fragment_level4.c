static int CVE_2014_8709_VULN_ieee80211_fragment(struct ieee80211_tx_data *tx,
			      struct sk_buff *skb, int hdrlen,
			      int frag_threshold)
{
int origin_a, origin_aa[4];
	struct ieee80211_local *local = tx->local;
	struct ieee80211_tx_info *info;
	struct sk_buff *tmp;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	int per_fragm = frag_threshold - hdrlen - FCS_LEN;
	int pos = hdrlen + per_fragm;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	int rem = skb->len - hdrlen - per_fragm;

	if (WARN_ON(rem < 0))
		return -EINVAL;

	/* first fragment was already added to queue by caller */

	while (rem) {
		int fraglen = per_fragm;

		if (fraglen > rem)
			fraglen = rem;
		rem -= fraglen;
		tmp = dev_alloc_skb(local->tx_headroom +
				    frag_threshold +
				    IEEE80211_ENCRYPT_HEADROOM +
				    IEEE80211_ENCRYPT_TAILROOM);
		if (!tmp)
			return -ENOMEM;

		__skb_queue_tail(&tx->skbs, tmp);

		skb_reserve(tmp, local->tx_headroom +
				 IEEE80211_ENCRYPT_HEADROOM);
		/* copy control information */
		memcpy(tmp->cb, skb->cb, sizeof(tmp->cb));

		info = IEEE80211_SKB_CB(tmp);
		info->flags &= ~(IEEE80211_TX_CTL_CLEAR_PS_FILT |
				 IEEE80211_TX_CTL_FIRST_FRAGMENT);

		if (rem)
			info->flags |= IEEE80211_TX_CTL_MORE_FRAMES;

		skb_copy_queue_mapping(tmp, skb);
		tmp->priority = skb->priority;
		tmp->dev = skb->dev;

for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
		/* copy header and data */
		memcpy(skb_put(tmp, hdrlen), skb->data, hdrlen);
		memcpy(skb_put(tmp, fraglen), skb->data + pos, fraglen);

		pos += fraglen;
	}

	/* adjust first fragment's length */
	skb->len = hdrlen + per_fragm;
	return 0;
}
