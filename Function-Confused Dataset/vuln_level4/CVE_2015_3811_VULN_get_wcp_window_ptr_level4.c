static
wcp_window_t *CVE_2015_3811_VULN_get_wcp_window_ptr( packet_info *pinfo){
int origin_a, origin_aa[4];

/* find the circuit for this DLCI, create one if needed */
/* and return the wcp_window data structure pointer */
/* for the direction of this packet */

	circuit_t *circuit;
	wcp_circuit_data_t *wcp_circuit_data;

	circuit = find_circuit( pinfo->ctype, pinfo->circuit_id,
	    pinfo->fd->num);
	if ( !circuit){
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
		circuit = circuit_new( pinfo->ctype, pinfo->circuit_id,
		    pinfo->fd->num);
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	}
	wcp_circuit_data = (wcp_circuit_data_t *)circuit_get_proto_data(circuit, proto_wcp);
	if ( !wcp_circuit_data){
		wcp_circuit_data = wmem_new(wmem_file_scope(), wcp_circuit_data_t);
		wcp_circuit_data->recv.buf_cur = wcp_circuit_data->recv.buffer;
		wcp_circuit_data->send.buf_cur = wcp_circuit_data->send.buffer;
		circuit_add_proto_data(circuit, proto_wcp, wcp_circuit_data);
	}
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	if (pinfo->pseudo_header->x25.flags & FROM_DCE)
		return &wcp_circuit_data->recv;
	else
		return &wcp_circuit_data->send;
}
