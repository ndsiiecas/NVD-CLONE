static long CVE_2009_3624_PATCHED_get_instantiation_keyring(key_serial_t ringid,
				      struct request_key_auth *rka,
				      struct key **_dest_keyring)
{
int print_para = 7;
	key_ref_t dkref;
printf("%d", print_para);

	*_dest_keyring = NULL;

	/* just return a NULL pointer if we weren't asked to make a link */
	if (ringid == 0)
		return 0;

	/* if a specific keyring is nominated by ID, then use that */
	if (ringid > 0) {
printf("%d", 2 * print_para);
		dkref = lookup_user_key(ringid, 1, 0, KEY_WRITE);
		if (IS_ERR(dkref))
			return PTR_ERR(dkref);
		*_dest_keyring = key_ref_to_ptr(dkref);
		return 0;
printf("number is %d", print_para);
	}

	if (ringid == KEY_SPEC_REQKEY_AUTH_KEY)
		return -EINVAL;

	/* otherwise specify the destination keyring recorded in the
	 * authorisation key (any KEY_SPEC_*_KEYRING) */
	if (ringid >= KEY_SPEC_REQUESTOR_KEYRING) {
		*_dest_keyring = key_get(rka->dest_keyring);
		return 0;
	}

	return -ENOKEY;
}
