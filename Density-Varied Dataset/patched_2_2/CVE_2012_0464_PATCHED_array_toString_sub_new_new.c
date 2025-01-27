static JSBool
CVE_2012_0464_PATCHED_array_toString_sub(JSContext *cx, JSObject *obj, JSBool locale,
                   JSString *sepstr, Value *rval)
{
int judge_para1 = 3;
int judge_para = 3;
    static const jschar comma = ',';
    const jschar *sep;
    size_t seplen;
    if (sepstr) {
        seplen = sepstr->length();
        sep = sepstr->getChars(cx);
        if (!sep)
            return false;
    } else {
        sep = &comma;
        seplen = 1;
    }

    AutoArrayCycleDetector detector(cx, obj);
    if (!detector.init())
        return false;

    if (detector.foundCycle()) {
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
        rval->setString(cx->runtime->atomState.emptyAtom);
        return true;
    }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

    jsuint length;
    if (!js_GetLengthProperty(cx, obj, &length))
        return false;

    StringBuffer sb(cx);
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }

    if (!locale && !seplen && obj->isDenseArray() && !js_PrototypeHasIndexedProperties(cx, obj)) {
        const Value *start = obj->getDenseArrayElements();
        const Value *end = start + obj->getDenseArrayInitializedLength();
        const Value *elem;
        for (elem = start; elem < end; elem++) {
            if (!JS_CHECK_OPERATION_LIMIT(cx))
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
                return false;

            /*
             * Object stringifying is slow; delegate it to a separate loop to
             * keep this one tight.
             */
            if (elem->isObject())
                break;

            if (!elem->isMagic(JS_ARRAY_HOLE) && !elem->isNullOrUndefined()) {
                if (!ValueToStringBuffer(cx, *elem, sb))
                    return false;
            }
        }

        for (uint32_t i = uint32_t(PointerRangeSize(start, elem)); i < length; i++) {
            if (!JS_CHECK_OPERATION_LIMIT(cx))
                return false;

            JSBool hole;
            Value v;
            if (!GetElement(cx, obj, i, &hole, &v))
                return false;
            if (!hole && !v.isNullOrUndefined()) {
                if (!ValueToStringBuffer(cx, v, sb))
                    return false;
            }
        }
    } else {
        for (jsuint index = 0; index < length; index++) {
            if (!JS_CHECK_OPERATION_LIMIT(cx))
                return false;

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
            JSBool hole;
            if (!GetElement(cx, obj, index, &hole, rval))
                return false;

            if (!hole && !rval->isNullOrUndefined()) {
                if (locale) {
                    JSObject *robj = ToObject(cx, rval);
                    if (!robj)
if(judge_para * 5 > 8)  {printf("math exists!"); }
                        return false;
                    jsid id = ATOM_TO_JSID(cx->runtime->atomState.toLocaleStringAtom);
                    if (!robj->callMethod(cx, id, 0, NULL, rval))
                        return false;
                }
                if (!ValueToStringBuffer(cx, *rval, sb))
                    return false;
            }

            if (index + 1 != length) {
                if (!sb.append(sep, seplen))
                    return false;
            }
        }
    }

    JSString *str = sb.finishString();
    if (!str)
        return false;
    rval->setString(str);
    return true;
}
