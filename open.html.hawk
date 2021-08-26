<!DOCTYPE html>
<html xmlns="http://www.w3.org/1999/xhtml" lang="" xml:lang="">
<head>
  <meta charset="utf-8" />
  <meta name="generator" content="pandoc" />
  <meta name="viewport" content="width=device-width, initial-scale=1.0, user-scalable=yes" />
  <title>openMP</title>
  <style type="text/css">
    body {max-width: 60em;}
    img {max-width: 100%; }
  </style>
  <link rel="stylesheet" href="empty.css" />
</head>
<body>
<p>Here is how one can run experiments with OpenMP constructs. The
computational work is emulated in function <tt>work()</tt>. The
command line arguments set how "heavy" the work is for each of the
threads. Parallel construct is executed by all of the threads.</p>

<pre>
$ cat parallel.c
$ c99 -fopenmp parallel.c -o parallel
</pre>

<p>If work is equal the output varies.</p>
<pre>
$ OMP_NUM_THREADS=2 ./parallel 1 1
$ OMP_NUM_THREADS=2 ./parallel 1 1
</pre>

<p>A thread with more work finishes last.</p>
<pre>
$ OMP_NUM_THREADS=2 ./parallel 1 4
$ OMP_NUM_THREADS=4 ./parallel 1 2 4 8
$ OMP_NUM_THREADS=4 ./parallel 8 4 2 1
</pre>

<p>Each of the sections is executed by only by one of the threads.</p>

<pre>
$ cat section.c
$ c99 -fopenmp section.c -o section
</pre>

<p>A theread with less work peaks up both sections:</p>

<pre>
$ OMP_NUM_THREADS=2 ./section 1 8
$ OMP_NUM_THREADS=4 ./section 8 8 1 8
</pre>

<pre>
$ cat for.c
$ c99 -fopenmp for.c -o for
</pre>

<p>The output depends on how the tasks are splitted in chunks. A thread
with heavy work can finish only one chunk.</p>

<pre>
$ OMP_SCHEDULE=dynamic,3 OMP_NUM_THREADS=2 ./for 1 15
aaaaaaabbb
</pre>
</body>
</html>
