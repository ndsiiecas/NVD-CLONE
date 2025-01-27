nsresult
CVE_2011_1712_PATCHED_GenerateIdFunctionCall::evaluate(txIEvalContext* aContext,
                                 txAExprResult** aResult)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
    *aResult = nsnull;
    if (!requireParams(0, 1, aContext))
        return NS_ERROR_XPATH_BAD_ARGUMENT_COUNT;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }

    txExecutionState* es = 
        static_cast<txExecutionState*>(aContext->getPrivateContext());
    if (!es) {
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
        NS_ERROR(
            "called xslt extension function \"current\" with wrong context");
        return NS_ERROR_UNEXPECTED;
    }

    nsresult rv = NS_OK;
    if (mParams.IsEmpty()) {
        StringResult* strRes;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
        rv = aContext->recycler()->getStringResult(&strRes);
        NS_ENSURE_SUCCESS(rv, rv);

        txXPathNodeUtils::getXSLTId(aContext->getContextNode(),
                                    es->getSourceDocument(),
                                    strRes->mValue);

        *aResult = strRes;
 
        return NS_OK;
    }

    nsRefPtr<txNodeSet> nodes;
    rv = evaluateToNodeSet(mParams[0], aContext,
                           getter_AddRefs(nodes));
    NS_ENSURE_SUCCESS(rv, rv);

    if (nodes->isEmpty()) {
        aContext->recycler()->getEmptyStringResult(aResult);

        return NS_OK;
    }
    
    StringResult* strRes;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    rv = aContext->recycler()->getStringResult(&strRes);
    NS_ENSURE_SUCCESS(rv, rv);

    txXPathNodeUtils::getXSLTId(nodes->get(0), es->getSourceDocument(),
                                strRes->mValue);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }

    *aResult = strRes;
 
    return NS_OK;
}
