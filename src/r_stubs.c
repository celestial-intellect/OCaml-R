/*********************************************************************************/
/*                OCaml-R                                                        */
/*                                                                               */
/*    Copyright (C) 2008-2010 Institut National de Recherche en                  */
/*    Informatique et en Automatique. All rights reserved.                       */
/*                                                                               */
/*    Copyright (C) 2009-2010 Guillaume Yziquel. All rights reserved.            */
/*                                                                               */
/*    This program is free software; you can redistribute it and/or modify       */
/*    it under the terms of the GNU General Public License as                    */
/*    published by the Free Software Foundation; either version 3 of the         */
/*    License, or  any later version.                                            */
/*                                                                               */
/*    This program is distributed in the hope that it will be useful,            */
/*    but WITHOUT ANY WARRANTY; without even the implied warranty of             */
/*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the               */
/*    GNU Library General Public License for more details.                       */
/*                                                                               */
/*    You should have received a copy of the GNU General Public                  */
/*    License along with this program; if not, write to the Free Software        */
/*    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA                   */
/*    02111-1307  USA                                                            */
/*                                                                               */
/*    Contact: Maxence.Guesdon@inria.fr                                          */
/*             guillaume.yziquel@citycable.ch                                    */
/*********************************************************************************/

//#define _GNU_SOURCE    /* Required by asprinft (see 'man asprintf'), as it is a
//                          GNU extension. Seems a bit overkill. Should try to
//                          remove this dependency on asprintf. */

#define USE_RINTERNALS /* This compilation directive allows us to have access to
                          the definition of R internal types. Compilation of the
                          inspect* functions is otherwise prohibited. */

#include <caml/mlvalues.h>
#include <caml/alloc.h>
#include <caml/memory.h>
#include <caml/fail.h>
#include <caml/callback.h>
#include <caml/signals.h>
#include <caml/custom.h>
#include <R.h>
#include <Rdefines.h>
#include <Rinternals.h>
#include <Rinterface.h>
#include <Rembedded.h>
#include <R_ext/Parse.h>
#include <stdio.h>

#include "initialisation.c"
#include "databridge.c"
#include "sexp.c"
#include "allocation.c"
#include "read_internal.c"
#include "write_internal.c"
#include "symbols.c"
#include "conversion.c"
#include "s3.c"
#include "s4.c"
#include "reduction.c"
#include "parser.c"



/* Code to audit. */

//CAMLprim value r_print_value (value sexp) {
//  PrintValue(Sexp_val(sexp));
//  return Val_unit;
//}

/* Commented out because of 'warning: assignment makes pointer from integer without a cast' */
//CAMLprim value r_exec (value fun_name, value args) {
//  CAMLparam2(fun_name, args);
//  CAMLlocal2(tmpval,tmpval2);
//  int nb_args = Wosize_val(args);
//  int i;
//  SEXP s, t, u;
//  int error = 0;
//  char* error_msg;
///*  prerr_endline (asprintf("%d args", nb_args));*/
//
//  PROTECT(t = s = allocList(nb_args + 1));
//  SET_TYPEOF(s, LANGSXP);
//  SETCAR(t, install(String_val(fun_name)));
//  for (i = 0; i < nb_args; i++) {
//    t = CDR(t);
//    tmpval = Field(args,i);
//    if (Is_block(tmpval)) {
//      tmpval2 = Field(tmpval,1);
//      if (Field(tmpval,0) == hash_variant("Named")) {
///*
//        prerr_endline("Named");
//        prerr_endline(String_val(Field(tmpval2,0)));
//*/
//        SET_TAG(t, install(String_val(Field(tmpval2,0))));
//        u = Long_val(Field(Field(tmpval2,1),0));
///*
//        PrintValue(u);
//*/
//        SETCAR(t, duplicate(u));
///*
//        prerr_endline("Named ok");
//*/
//      } else if (Field(tmpval,0) == hash_variant("Anon")) {
///*
//        prerr_endline ("Anon");
//*/
//        u = Long_val(Field(tmpval2,0));
///*
//        PrintValue(u);
//*/
//        SETCAR(t, duplicate(u));
///*
//        prerr_endline ("Anon ok");
//*/
//      } else {
//        prerr_endline("bad constructor");
//        /* bad constructor */
//      }
//
//    }  else
//    {
//      /* no argument, bad value for us */
//      prerr_endline("no block, bad value");
//    }
//  }
//  R_tryEval(s, R_GlobalEnv, &error);
//  UNPROTECT(1);
//  if (error) {
//    asprintf(&error_msg, "R failure while calling function '%s'.", String_val(fun_name));
//    caml_failwith(error_msg);
//  }
//  CAMLreturn(Val_unit);
//}
