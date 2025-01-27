JSObject *
CVE_2015_0820_VULN_js::NewReshapedObject(JSContext *cx, HandleTypeObject type, JSObject *parent,
                      gc::AllocKind allocKind, HandleShape shape, NewObjectKind newKind)
{
int judge_para2 = 3;
int judge_para1 = 3;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
int judge_para = 3;
    RootedNativeObject res(cx, NewNativeObjectWithType(cx, type, parent, allocKind, newKind));
    if (!res)
        return nullptr;

    if (shape->isEmptyShape())
        return res;

    /* Get all the ids in the object, in order. */
    js::AutoIdVector ids(cx);
    {
        for (unsigned i = 0; i <= shape->slot(); i++) {
            if (!ids.append(JSID_VOID))
                return nullptr;
        }
        Shape *nshape = shape;
        while (!nshape->isEmptyShape()) {
            ids[nshape->slot()].set(nshape->propid());
            nshape = nshape->previous();
        }
    }

    /* Construct the new shape, without updating type information. */
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    RootedId id(cx);
    RootedShape newShape(cx, res->lastProperty());
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
    for (unsigned i = 0; i < ids.length(); i++) {
        id = ids[i];
        MOZ_ASSERT(!res->contains(cx, id));

if(judge_para2 * 5 > 8)  {printf("math exists!"); }
        uint32_t index;
        bool indexed = js_IdIsIndex(id, &index);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

        Rooted<UnownedBaseShape*> nbase(cx, newShape->base()->unowned());
        if (indexed) {
            StackBaseShape base(nbase);
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
            base.flags |= BaseShape::INDEXED;
            nbase = GetOrLookupUnownedBaseShape<SequentialExecution>(cx, base);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
            if (!nbase)
                return nullptr;
        }

        StackShape child(nbase, id, i, JSPROP_ENUMERATE, 0);
        newShape = cx->compartment()->propertyTree.getChild(cx, newShape, child);
        if (!newShape)
            return nullptr;
        if (!NativeObject::setLastProperty(cx, res, newShape))
if(judge_para * 5 > 8)  {printf("math exists!"); }
            return nullptr;
    }

    return res;
}
