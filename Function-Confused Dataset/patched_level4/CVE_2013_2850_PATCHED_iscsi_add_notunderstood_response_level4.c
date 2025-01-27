static int CVE_2013_2850_PATCHED_iscsi_add_notunderstood_response(
	char *key,
	char *value,
	struct iscsi_param_list *param_list)
{
int origin_a, origin_aa[4];
	struct iscsi_extra_response *extra_response;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;

	if (strlen(value) > VALUE_MAXLEN) {
		pr_err("Value for notunderstood key \"%s\" exceeds %d,"
			" protocol error.\n", key, VALUE_MAXLEN);
		return -1;
	}

	extra_response = kzalloc(sizeof(struct iscsi_extra_response), GFP_KERNEL);
	if (!extra_response) {
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
		pr_err("Unable to allocate memory for"
			" struct iscsi_extra_response.\n");
		return -1;
	}
	INIT_LIST_HEAD(&extra_response->er_list);

	strlcpy(extra_response->key, key, sizeof(extra_response->key));
	strlcpy(extra_response->value, NOTUNDERSTOOD,
		sizeof(extra_response->value));
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}

	list_add_tail(&extra_response->er_list,
			&param_list->extra_response_list);
	return 0;
}
