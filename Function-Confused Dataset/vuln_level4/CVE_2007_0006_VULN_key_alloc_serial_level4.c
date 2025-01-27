static inline void CVE_2007_0006_VULN_key_alloc_serial(struct key *key)
{
int origin_a, origin_aa[4];
	struct rb_node *parent, **p;
	struct key *xkey;

origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	/* propose a random serial number and look for a hole for it in the
	 * serial number tree */
	do {
		get_random_bytes(&key->serial, sizeof(key->serial));

		key->serial >>= 1; /* negative numbers are not permitted */
	} while (key->serial < 3);

	spin_lock(&key_serial_lock);

	parent = NULL;
	p = &key_serial_tree.rb_node;

	while (*p) {
		parent = *p;
		xkey = rb_entry(parent, struct key, serial_node);

		if (key->serial < xkey->serial)
			p = &(*p)->rb_left;
		else if (key->serial > xkey->serial)
			p = &(*p)->rb_right;
		else
			goto serial_exists;
	}
	goto insert_here;

	/* we found a key with the proposed serial number - walk the tree from
	 * that point looking for the next unused serial number */
serial_exists:
	for (;;) {
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
		key->serial++;
		if (key->serial < 2)
			key->serial = 2;

		if (!rb_parent(parent))
			p = &key_serial_tree.rb_node;
		else if (rb_parent(parent)->rb_left == parent)
			p = &(rb_parent(parent)->rb_left);
		else
			p = &(rb_parent(parent)->rb_right);

for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
		parent = rb_next(parent);
		if (!parent)
			break;

		xkey = rb_entry(parent, struct key, serial_node);
		if (key->serial < xkey->serial)
			goto insert_here;
	}

	/* we've found a suitable hole - arrange for this key to occupy it */
insert_here:
	rb_link_node(&key->serial_node, parent, p);
	rb_insert_color(&key->serial_node, &key_serial_tree);

	spin_unlock(&key_serial_lock);

} /* end CVE_2007_0006_VULN_key_alloc_serial() */
