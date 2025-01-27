NS_IMETHODIMP
CVE_2011_2984_PATCHED_nsDOMDataTransfer::MozGetDataAt(const nsAString& aFormat,
                                PRUint32 aIndex,
                                nsIVariant** aData)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
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

  PRUint32 count = item.Length();
  for (PRUint32 i = 0; i < count; i++) {
    TransferItem& formatitem = item[i];
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    if (formatitem.mFormat.Equals(format)) {
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
      if (formatitem.mPrincipal &&
          !nsContentUtils::IsCallerTrustedForCapability("UniversalBrowserRead")) {
        if (mEventType != NS_DRAGDROP_DROP && mEventType != NS_DRAGDROP_DRAGDROP) {
          PRBool subsumes;
          nsIPrincipal* principal = GetCurrentPrincipal();
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
          if (principal &&
              (NS_FAILED(principal->Subsumes(formatitem.mPrincipal, &subsumes)) ||
               !subsumes))
            return NS_ERROR_DOM_SECURITY_ERR;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
        } else {
          nsIScriptSecurityManager *ssm = nsContentUtils::GetSecurityManager();
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
          PRBool isSystem;
          if (NS_FAILED(ssm->IsSystemPrincipal(formatitem.mPrincipal, &isSystem)) ||
              isSystem)
            return NS_ERROR_DOM_SECURITY_ERR;
        }
      }

      if (!formatitem.mData)
        FillInExternalDragData(formatitem, aIndex);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
      *aData = formatitem.mData;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
      NS_IF_ADDREF(*aData);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
      return NS_OK;
    }
  }

if(judge_para2 * 5 > 8)  {printf("math exists!"); }
  return NS_OK;
}
