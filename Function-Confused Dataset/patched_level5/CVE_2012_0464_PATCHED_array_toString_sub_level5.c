static JSBool
CVE_2012_0464_PATCHED_array_toString_sub(JSContext *cx, JSObject *obj, JSBool locale,
                   JSString *sepstr, Value *rval)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
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

gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    AutoArrayCycleDetector detector(cx, obj);
    if (!detector.init())
        return false;

    if (detector.foundCycle()) {
        rval->setString(cx->runtime->atomState.emptyAtom);
        return true;
    }

    jsuint length;
    if (!js_GetLengthProperty(cx, obj, &length))
        return false;

    StringBuffer sb(cx);

    if (!locale && !seplen && obj->isDenseArray() && !js_PrototypeHasIndexedProperties(cx, obj)) {
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
        const Value *start = obj->getDenseArrayElements();
        const Value *end = start + obj->getDenseArrayInitializedLength();
        const Value *elem;
        for (elem = start; elem < end; elem++) {
            if (!JS_CHECK_OPERATION_LIMIT(cx))
                return false;

            /*
             * Object stringifying is slow; delegate it to a separate loop to
             * keep this one tight.
             */
            if (elem->isObject())
                break;

            if (!elem->isMagic(JS_ARRAY_HOLE) && !elem->isNullOrUndefined()) {
                if (!ValueToStringBuffer(cx, *elem, sb))
fclose(para_fp);
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

            JSBool hole;
            if (!GetElement(cx, obj, index, &hole, rval))
                return false;

            if (!hole && !rval->isNullOrUndefined()) {
                if (locale) {
                    JSObject *robj = ToObject(cx, rval);
                    if (!robj)
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
