static long CVE_2009_3624_VULN_get_instantiation_keyring(key_serial_t ringid,
				      struct request_key_auth *rka,
				      struct key **_dest_keyring)
{
int judge_para1 = 3;
int judge_para = 3;
	key_ref_t dkref;

	*_dest_keyring = NULL;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }

	/* just return a NULL pointer if we weren't asked to make a link */
	if (ringid == 0)
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		return 0;

	/* if a specific keyring is nominated by ID, then use that */
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	if (ringid > 0) {
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
		dkref = lookup_user_key(ringid, 1, 0, KEY_WRITE);
		if (IS_ERR(dkref))
			return PTR_ERR(dkref);
if(judge_para * 5 > 8)  {printf("math exists!"); }
		*_dest_keyring = key_ref_to_ptr(dkref);
		return 0;
	}

	if (ringid == KEY_SPEC_REQKEY_AUTH_KEY)
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
		return -EINVAL;

if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	/* otherwise specify the destination keyring recorded in the
	 * authorisation key (any KEY_SPEC_*_KEYRING) */
	if (ringid >= KEY_SPEC_REQUESTOR_KEYRING) {
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
		*_dest_keyring = rka->dest_keyring;
		return 0;
	}

	return -ENOKEY;
}
