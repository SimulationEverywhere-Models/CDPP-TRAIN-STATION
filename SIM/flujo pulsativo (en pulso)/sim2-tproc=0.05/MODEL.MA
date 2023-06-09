[top]
components : prod@Productor mod_flujo
Out : out
Link : out@prod in@mod_flujo
Link : out@mod_flujo out

[prod]
tact : 10
tpas : 5
cp : 100

[proc1_1]
tproc : 0.05

[proc1_2]
tproc : 0.05

[proc1_3]
tproc : 0.05

[proc1_4]
tproc : 0.05

[proc2_1]
tproc : 0.05

[proc2_2]
tproc : 0.05

[proc2_3]
tproc : 0.05

[proc2_4]
tproc : 0.05

[mod_flujo]
components : proc_flujo1 proc_flujo2
In : in
Out : out
Link : in in@proc_flujo1
Link : out@proc_flujo1 in@proc_flujo2
Link : out@proc_flujo2 out 

[proc_flujo1]
components : dist1@Distribuidor 
components : cola1_1@Cola proc1_1@Proc 
components : cola1_2@Cola proc1_2@Proc 
components : cola1_3@Cola proc1_3@Proc 
components : cola1_4@Cola proc1_4@Proc 

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

Link : out3@dist1 in@cola1_3
Link : out@cola1_3 in@proc1_3
Link : out@proc1_3 r3@dist1
Link : out@proc1_3 out
Link : out@proc1_3 r@cola1_3

Link : out4@dist1 in@cola1_4
Link : out@cola1_4 in@proc1_4
Link : out@proc1_4 r4@dist1
Link : out@proc1_4 out
Link : out@proc1_4 r@cola1_4

[proc_flujo2]
components : dist2@Distribuidor 
components : cola2_1@Cola proc2_1@Proc 
components : cola2_2@Cola proc2_2@Proc 
components : cola2_3@Cola proc2_3@Proc 
components : cola2_4@Cola proc2_4@Proc 

In : in
Out : out
Link : in in@dist2 

Link : out1@dist2 in@cola2_1
Link : out@cola2_1 in@proc2_1
Link : out@proc2_1 r1@dist2
Link : out@proc2_1 out
Link : out@proc2_1 r@cola2_1

Link : out2@dist2 in@cola2_2
Link : out@cola2_2 in@proc2_2
Link : out@proc2_2 r2@dist2
Link : out@proc2_2 out
Link : out@proc2_2 r@cola2_2

Link : out3@dist2 in@cola2_3
Link : out@cola2_3 in@proc2_3
Link : out@proc2_3 r3@dist2
Link : out@proc2_3 out
Link : out@proc2_3 r@cola2_3

Link : out4@dist2 in@cola2_4
Link : out@cola2_4 in@proc2_4
Link : out@proc2_4 r4@dist2
Link : out@proc2_4 out
Link : out@proc2_4 r@cola2_4

