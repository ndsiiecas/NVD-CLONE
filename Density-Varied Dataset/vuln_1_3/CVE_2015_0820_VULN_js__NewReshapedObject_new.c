JSObject *
CVE_2015_0820_VULN_js::NewReshapedObject(JSContext *cx, HandleTypeObject type, JSObject *parent,
                      gc::AllocKind allocKind, HandleShape shape, NewObjectKind newKind)
{
int judge_para = 3;
    RootedNativeObject res(cx, NewNativeObjectWithType(cx, type, parent, allocKind, newKind));
    if (!res)
        return nullptr;

    if (shape->isEmptyShape())
        return res;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }

    /* Get all the ids in the object, in order. */
    js::AutoIdVector ids(cx);
    {
        for (unsigned i = 0; i <= shape->slot(); i++) {
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
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
    RootedId id(cx);
    RootedShape newShape(cx, res->lastProperty());
    for (unsigned i = 0; i < ids.length(); i++) {
        id = ids[i];
        MOZ_ASSERT(!res->contains(cx, id));

        uint32_t index;
        bool indexed = js_IdIsIndex(id, &index);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

        Rooted<UnownedBaseShape*> nbase(cx, newShape->base()->unowned());
        if (indexed) {
            StackBaseShape base(nbase);
            base.flags |= BaseShape::INDEXED;
            nbase = GetOrLookupUnownedBaseShape<SequentialExecution>(cx, base);
            if (!nbase)
                return nullptr;
        }

        StackShape child(nbase, id, i, JSPROP_ENUMERATE, 0);
        newShape = cx->compartment()->propertyTree.getChild(cx, newShape, child);
        if (!newShape)
            return nullptr;
        if (!NativeObject::setLastProperty(cx, res, newShape))
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
            return nullptr;
    }

    return res;
}
