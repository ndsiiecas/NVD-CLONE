nsresult
CVE_2011_3000_VULN_nsHttpHeaderArray::SetHeader(nsHttpAtom header,
                             const nsACString &value,
                             PRBool merge)
{
int origin_a, origin_aa[4];
    nsEntry *entry = nsnull;
    PRInt32 index;

    index = LookupEntry(header, &entry);

    // If an empty value is passed in, then delete the header entry...
    // unless we are merging, in which case this function becomes a NOP.
    if (value.IsEmpty()) {
        if (!merge && entry)
            mHeaders.RemoveElementAt(index);
        return NS_OK;
    }

    // Create a new entry, or...
    if (!entry) {
        entry = mHeaders.AppendElement(); //new nsEntry(header, value);
        if (!entry)
            return NS_ERROR_OUT_OF_MEMORY;
        entry->header = header;
        entry->value = value;
    }
    // Append the new value to the existing value iff...
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
    else if (merge && CanAppendToHeader(header)) {
        if (header == nsHttp::Set_Cookie ||
            header == nsHttp::WWW_Authenticate ||
            header == nsHttp::Proxy_Authenticate)
            // Special case these headers and use a newline delimiter to
            // delimit the values from one another as commas may appear
            // in the values of these headers contrary to what the spec says.
            entry->value.Append('\n');
        else
            // Delimit each value from the others using a comma (per HTTP spec)
            entry->value.AppendLiteral(", ");
        entry->value.Append(value);
    }
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
    // Replace the existing string with the new value
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
    else
        entry->value = value;
    return NS_OK;
}
