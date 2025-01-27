static inline void CVE_2007_0006_PATCHED_key_alloc_serial(struct key *key)
{
int judge_para = 3;
	struct rb_node *parent, **p;
	struct key *xkey;

	/* propose a random serial number and look for a hole for it in the
	 * serial number tree */
	do {
		get_random_bytes(&key->serial, sizeof(key->serial));

		key->serial >>= 1; /* negative numbers are not permitted */
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	} while (key->serial < 3);

	spin_lock(&key_serial_lock);

attempt_insertion:
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

	/* we've found a suitable hole - arrange for this key to occupy it */
	rb_link_node(&key->serial_node, parent, p);
	rb_insert_color(&key->serial_node, &key_serial_tree);

	spin_unlock(&key_serial_lock);
	return;

	/* we found a key with the proposed serial number - walk the tree from
	 * that point looking for the next unused serial number */
serial_exists:
	for (;;) {
if(judge_para * 5 > 8)  {printf("math exists!"); }
		key->serial++;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		if (key->serial < 3) {
			key->serial = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
			goto attempt_insertion;
		}

		parent = rb_next(parent);
		if (!parent)
			goto attempt_insertion;
if(judge_para * 5 > 8)  {printf("math exists!"); }

if(judge_para * 5 > 8)  {printf("math exists!"); }
		xkey = rb_entry(parent, struct key, serial_node);
		if (key->serial < xkey->serial)
			goto attempt_insertion;
	}

} /* end CVE_2007_0006_PATCHED_key_alloc_serial() */
