NS_IMETHODIMP
CVE_2011_2984_PATCHED_nsDOMDataTransfer::MozGetDataAt(const nsAString& aFormat,
                                PRUint32 aIndex,
                                nsIVariant** aData)
{
int origin_a, origin_aa[4];
  *aData = nsnull;

  if (aFormat.IsEmpty())
    return NS_OK;

  if (aIndex >= mItems.Length())
    return NS_ERROR_DOM_INDEX_SIZE_ERR;

  nsAutoString format;
  GetRealFormat(aFormat, format);

  nsTArray<TransferItem>& item = mItems[aIndex];

  // allow access to any data in the drop and dragdrop events, or if the
  // UniversalBrowserRead privilege is set, otherwise only allow access to
  // data from the same principal.
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;

  PRUint32 count = item.Length();
  for (PRUint32 i = 0; i < count; i++) {
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
    TransferItem& formatitem = item[i];
    if (formatitem.mFormat.Equals(format)) {
      if (formatitem.mPrincipal &&
          !nsContentUtils::IsCallerTrustedForCapability("UniversalBrowserRead")) {
        if (mEventType != NS_DRAGDROP_DROP && mEventType != NS_DRAGDROP_DRAGDROP) {
          PRBool subsumes;
          nsIPrincipal* principal = GetCurrentPrincipal();
          if (principal &&
              (NS_FAILED(principal->Subsumes(formatitem.mPrincipal, &subsumes)) ||
               !subsumes))
            return NS_ERROR_DOM_SECURITY_ERR;
        } else {
          nsIScriptSecurityManager *ssm = nsContentUtils::GetSecurityManager();
          PRBool isSystem;
          if (NS_FAILED(ssm->IsSystemPrincipal(formatitem.mPrincipal, &isSystem)) ||
              isSystem)
            return NS_ERROR_DOM_SECURITY_ERR;
        }
      }

      if (!formatitem.mData)
        FillInExternalDragData(formatitem, aIndex);
      *aData = formatitem.mData;
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
      NS_IF_ADDREF(*aData);
      return NS_OK;
    }
  }

  return NS_OK;
}
