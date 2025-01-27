static long CVE_2009_3624_PATCHED_get_instantiation_keyring(key_serial_t ringid,
				      struct request_key_auth *rka,
				      struct key **_dest_keyring)
{
int origin_a, origin_aa[4];
	key_ref_t dkref;

	*_dest_keyring = NULL;

	/* just return a NULL pointer if we weren't asked to make a link */
	if (ringid == 0)
		return 0;

	/* if a specific keyring is nominated by ID, then use that */
	if (ringid > 0) {
		dkref = lookup_user_key(ringid, 1, 0, KEY_WRITE);
		if (IS_ERR(dkref))
			return PTR_ERR(dkref);
		*_dest_keyring = key_ref_to_ptr(dkref);
		return 0;
	}

	if (ringid == KEY_SPEC_REQKEY_AUTH_KEY)
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
		return -EINVAL;

for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	/* otherwise specify the destination keyring recorded in the
	 * authorisation key (any KEY_SPEC_*_KEYRING) */
	if (ringid >= KEY_SPEC_REQUESTOR_KEYRING) {
		*_dest_keyring = key_get(rka->dest_keyring);
		return 0;
	}

	return -ENOKEY;
}
