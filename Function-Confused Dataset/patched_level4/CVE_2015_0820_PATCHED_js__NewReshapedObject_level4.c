JSObject *
CVE_2015_0820_PATCHED_js::NewReshapedObject(JSContext *cx, HandleTypeObject type, JSObject *parent,
                      gc::AllocKind allocKind, HandleShape shape, NewObjectKind newKind)
{
int origin_a, origin_aa[4];
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
    RootedId id(cx);
    RootedShape newShape(cx, EmptyShape::getInitialShape(cx, res->getClass(),
                                                         res->getTaggedProto(),
                                                         res->getMetadata(),
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
                                                         res->getParent(),
                                                         res->numFixedSlots(),
                                                         shape->getObjectFlags()));
    for (unsigned i = 0; i < ids.length(); i++) {
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
        id = ids[i];
        MOZ_ASSERT(!res->contains(cx, id));

        uint32_t index;
        bool indexed = js_IdIsIndex(id, &index);

        Rooted<UnownedBaseShape*> nbase(cx, newShape->base()->unowned());
        if (indexed) {
            StackBaseShape base(nbase);
            base.flags |= BaseShape::INDEXED;
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
            nbase = GetOrLookupUnownedBaseShape<SequentialExecution>(cx, base);
            if (!nbase)
                return nullptr;
        }

        StackShape child(nbase, id, i, JSPROP_ENUMERATE, 0);
        newShape = cx->compartment()->propertyTree.getChild(cx, newShape, child);
        if (!newShape)
            return nullptr;
        if (!NativeObject::setLastProperty(cx, res, newShape))
            return nullptr;
    }

    return res;
}
