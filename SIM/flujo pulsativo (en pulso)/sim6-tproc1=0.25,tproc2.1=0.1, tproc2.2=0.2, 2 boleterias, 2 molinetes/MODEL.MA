[top]
components : prod@Productor mod_flujo
Out : out1 out2
Link : out@prod in@mod_flujo
Link : out1@mod_flujo out1
Link : out2@mod_flujo out2


[prod]
tact : 10
tpas : 10
cp : 10

[proc1_1]
tproc : 0.25

[proc1_2]
tproc : 0.25

[proc1_3]
tproc : 0.25

[proc1_4]
tproc : 0.25

[proc2_1]
tproc : 0.3

[proc2_2]
tproc : 0.6

[proc2_3]
tproc : 0.25

[proc2_4]
tproc : 0.25

[mod_flujo]
components : proc_flujo1 proc_flujo2
In : in
Out : out1 out2
Link : in in@proc_flujo1
Link : out@proc_flujo1 in@proc_flujo2
Link : out1@proc_flujo2 out1
Link : out2@proc_flujo2 out2


[proc_flujo1]
components : dist1@Distribuidor 
components : cola1_1@Cola proc1_1@Proc 
components : cola1_2@Cola proc1_2@Proc 

In : in
Out : out
Link : in in@dist1 

Link : out1@dist1 in@cola1_1
Link : out@cola1_1 in@proc1_1
Link : out@proc1_1 r1@dist1
Link : out@proc1_1 out
Link : out@proc1_1 r@cola1_1

Link : out2@dist1 in@cola1_2
Link : out@cola1_2 in@proc1_2
Link : out@proc1_2 r2@dist1
Link : out@proc1_2 out
Link : out@proc1_2 r@cola1_2

[dist1]
p1 : 0
p2 : 0
p3 : 100000
p4 : 100000

[proc_flujo2]
components : dist2@Distribuidor 
components : cola2_1@Cola proc2_1@Proc 
components : cola2_2@Cola proc2_2@Proc 

In : in
Out : out1 out2
Link : in in@dist2 

Link : out1@dist2 in@cola2_1
Link : out@cola2_1 in@proc2_1
Link : out@proc2_1 r1@dist2
Link : out@proc2_1 out1
Link : out@proc2_1 r@cola2_1

Link : out2@dist2 in@cola2_2
Link : out@cola2_2 in@proc2_2
Link : out@proc2_2 r2@dist2
Link : out@proc2_2 out2
Link : out@proc2_2 r@cola2_2

[dist2]
p1 : 0
p2 : 0
p3 : 100000
p4 : 100000

