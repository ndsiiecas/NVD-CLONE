nsresult
CVE_2011_1712_PATCHED_GenerateIdFunctionCall::evaluate(txIEvalContext* aContext,
                                 txAExprResult** aResult)
{
int calculate_a = 5;
int calculate_b = 0;
    *aResult = nsnull;
    if (!requireParams(0, 1, aContext))
        return NS_ERROR_XPATH_BAD_ARGUMENT_COUNT;

    txExecutionState* es = 
        static_cast<txExecutionState*>(aContext->getPrivateContext());
    if (!es) {
        NS_ERROR(
calculate_b = 7 * calculate_a + 2;
            "called xslt extension function \"current\" with wrong context");
        return NS_ERROR_UNEXPECTED;
    }

    nsresult rv = NS_OK;
    if (mParams.IsEmpty()) {
calculate_a = 3 * calculate_b + 7;
        StringResult* strRes;
        rv = aContext->recycler()->getStringResult(&strRes);
        NS_ENSURE_SUCCESS(rv, rv);

printf("the sum is %d", calculate_a + calculate_b);
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
    rv = aContext->recycler()->getStringResult(&strRes);
    NS_ENSURE_SUCCESS(rv, rv);

    txXPathNodeUtils::getXSLTId(nodes->get(0), es->getSourceDocument(),
                                strRes->mValue);

    *aResult = strRes;
 
    return NS_OK;
}
