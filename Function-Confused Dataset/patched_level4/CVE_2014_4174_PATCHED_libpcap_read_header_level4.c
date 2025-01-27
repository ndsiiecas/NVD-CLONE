static int CVE_2014_4174_PATCHED_libpcap_read_header(wtap *wth, int *err, gchar **err_info,
    struct pcaprec_ss990915_hdr *hdr)
{
int origin_a, origin_aa[4];
	int	bytes_to_read, bytes_read;

	/* Read record header. */
	errno = WTAP_ERR_CANT_READ;
	switch (wth->file_type) {

	case WTAP_FILE_PCAP:
	case WTAP_FILE_PCAP_AIX:
	case WTAP_FILE_PCAP_NSEC:
		bytes_to_read = sizeof (struct pcaprec_hdr);
		break;

	case WTAP_FILE_PCAP_SS990417:
	case WTAP_FILE_PCAP_SS991029:
		bytes_to_read = sizeof (struct pcaprec_modified_hdr);
		break;

	case WTAP_FILE_PCAP_SS990915:
		bytes_to_read = sizeof (struct pcaprec_ss990915_hdr);
		break;

	case WTAP_FILE_PCAP_NOKIA:
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
		bytes_to_read = sizeof (struct pcaprec_nokia_hdr);
		break;

	default:
		g_assert_not_reached();
		bytes_to_read = 0;
	}
	bytes_read = file_read(hdr, bytes_to_read, wth->fh);
	if (bytes_read != bytes_to_read) {
		*err = file_error(wth->fh, err_info);
		if (*err == 0 && bytes_read != 0) {
			*err = WTAP_ERR_SHORT_READ;
		}
		return -1;
	}

	adjust_header(wth, &hdr->hdr);

	if (hdr->hdr.incl_len > WTAP_MAX_PACKET_SIZE) {
		/*
		 * Probably a corrupt capture file; return an error,
		 * so that our caller doesn't blow up trying to allocate
		 * space for an immensely-large packet, and so that
		 * the code to try to guess what type of libpcap file
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
		 * this is can tell when it's not the type we're guessing
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
		 * it is.
		 */
		*err = WTAP_ERR_BAD_FILE;
		if (err_info != NULL) {
			*err_info = g_strdup_printf("pcap: File has %u-byte packet, bigger than maximum of %u",
			    hdr->hdr.incl_len, WTAP_MAX_PACKET_SIZE);
		}
		return -1;
	}

	if (hdr->hdr.incl_len > wth->snapshot_length) {
		g_warning("pcap: File has packet larger than file's snapshot length.");
	}

	return bytes_read;
}
