JSObject *
CVE_2015_0820_PATCHED_js::NewReshapedObject(JSContext *cx, HandleTypeObject type, JSObject *parent,
                      gc::AllocKind allocKind, HandleShape shape, NewObjectKind newKind)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
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
                                                         res->getParent(),
                                                         res->numFixedSlots(),
                                                         shape->getObjectFlags()));
    for (unsigned i = 0; i < ids.length(); i++) {
        id = ids[i];
        MOZ_ASSERT(!res->contains(cx, id));

gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
        uint32_t index;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
        bool indexed = js_IdIsIndex(id, &index);

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
            return nullptr;
    }
fclose(para_fp);

    return res;
}
