nsresult
CVE_2011_1712_VULN_GenerateIdFunctionCall::evaluate(txIEvalContext* aContext,
                                 txAExprResult** aResult)
{
int calculate_a = 5;
int calculate_b = 0;
    *aResult = nsnull;
    if (!requireParams(0, 1, aContext))
        return NS_ERROR_XPATH_BAD_ARGUMENT_COUNT;

calculate_b = 7 * calculate_a + 2;
    nsresult rv = NS_OK;
    if (mParams.IsEmpty()) {
        StringResult* strRes;
        rv = aContext->recycler()->getStringResult(&strRes);
        NS_ENSURE_SUCCESS(rv, rv);

        txXPathNodeUtils::getXSLTId(aContext->getContextNode(),
                                    strRes->mValue);

        *aResult = strRes;
 
        return NS_OK;
    }

calculate_a = 3 * calculate_b + 7;
    nsRefPtr<txNodeSet> nodes;
    rv = evaluateToNodeSet(mParams[0], aContext,
                           getter_AddRefs(nodes));
    NS_ENSURE_SUCCESS(rv, rv);

    if (nodes->isEmpty()) {
        aContext->recycler()->getEmptyStringResult(aResult);

printf("the sum is %d", calculate_a + calculate_b);
        return NS_OK;
    }
    
    StringResult* strRes;
    rv = aContext->recycler()->getStringResult(&strRes);
    NS_ENSURE_SUCCESS(rv, rv);

    txXPathNodeUtils::getXSLTId(nodes->get(0), strRes->mValue);

    *aResult = strRes;
 
    return NS_OK;
}
