[top]
components : dist@Distribuidor 
components : cola1@Cola proc1@Proc 
components : cola2@Cola proc2@Proc 
components : cola3@Cola proc3@Proc 
components : cola4@Cola proc4@Proc 

In : in
Out : out
Link : in in@dist 

Link : out1@dist in@cola1
Link : out@cola1 in@proc1
Link : out@cola1 r1@dist
Link : out@proc1 r@cola1

Link : out2@dist in@cola2
Link : out@cola2 in@proc2
Link : out@cola2 r2@dist
Link : out@proc2 r@cola2

Link : out3@dist in@cola3
Link : out@cola3 in@proc3
Link : out@cola3 r3@dist
Link : out@proc3 r@cola3

Link : out4@dist in@cola4
Link : out@cola4 in@proc4
Link : out@cola4 r4@dist
Link : out@proc4 r@cola4

Link : out@proc1 out
Link : out@proc2 out
Link : out@proc3 out
Link : out@proc4 out


[dist]
p1 : 0
p2 : 0
p3 : 0
p4 : 0

[proc1]
tproc : 2

[proc2]
tproc : 2

[proc3]
tproc : 2

[proc4]
tproc : 2

[cola1]

[cola2]

[cola3]

[cola4]
