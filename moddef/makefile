#
# /emx/src/lib/moddef/makefile
#
.INCLUDE: /emx/src/lib/lib0.mak

.SOURCE.c: ..
.SOURCE.h: ..

.PHONY: clean default dstlib moddef

MD=$(I)sys/moddef.h

LIBMODDEF=$(L)moddef.a

default: moddef

moddef .SETDIR=$(CPU):
	$(MAKE) -f ../makefile dstlib $(PASSDOWN)

dstlib: $(LIBMODDEF)

clean:
	-del $(CPU)\*.o $(DELOPT)

moddef1.o: moddef1.c $(MD) $(I)stdio.h $(I)stdlib.h $(I)string.h $(ERRNO) \
                     $(I)ctype.h $(I)share.h
moddef2.o: moddef2.c $(MD) $(I)stdio.h
moddef3.o: moddef3.c $(MD) $(I)stdio.h

$(LIBMODDEF): moddef1.o moddef2.o moddef3.o
	-del $(LIBMODDEF)
	$(AR) r $(LIBMODDEF) *.o
