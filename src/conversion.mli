(*********************************************************************************)
(*                OCaml-R                                                        *)
(*                                                                               *)
(*    Copyright (C) 2008-2010 Institut National de Recherche en                  *)
(*    Informatique et en Automatique. All rights reserved.                       *)
(*                                                                               *)
(*    Copyright (C) 2009-2010 Guillaume Yziquel. All rights reserved.            *)
(*                                                                               *)
(*    This program is free software; you can redistribute it and/or modify       *)
(*    it under the terms of the GNU General Public License as                    *)
(*    published by the Free Software Foundation; either version 3 of the         *)
(*    License, or  any later version.                                            *)
(*                                                                               *)
(*    This program is distributed in the hope that it will be useful,            *)
(*    but WITHOUT ANY WARRANTY; without even the implied warranty of             *)
(*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the               *)
(*    GNU Library General Public License for more details.                       *)
(*                                                                               *)
(*    You should have received a copy of the GNU General Public                  *)
(*    License along with this program; if not, write to the Free Software        *)
(*    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA                   *)
(*    02111-1307  USA                                                            *)
(*                                                                               *)
(*    Contact: Maxence.Guesdon@inria.fr                                          *)
(*             guillaume.yziquel@citycable.ch                                    *)
(*********************************************************************************)

(** {2 Conversion functions.} *)

val bools_of_t : bool list t -> bool list
(**  Converts an R array of logical values into a list of Objective
  *  Caml booleans.
  *)

val bool_of_t : bool t -> bool
(**  Converts an R array of logical values with one element into an
  *  Objective Caml boolean.
  *)

val bool : bool -> bool t
(**  Converts an Objective Caml boolean value to an R boolean value,
  *  that is a mono-element array of booleans.
  *) 

val bools : bool list -> bool list t
(**  Converts an Objective Caml list of booleans into an R array
  *  of logical values.
  *)

val ints_of_t : int list t -> int list
(**  Converts an R array of integers into a list of Objective Caml
  *  integers.
  *)

val int_of_t : int t -> int
(**  Converts an R array of integers with one element into an Objective
  *  Caml integer.
  *)

val int : int -> int t
(**  Converts an Objective Caml integer to an R integer value, that
  *  is a mono-element array of integers.
  *)

val ints : int list -> int list t
(**  Converts an Objective Caml list of integers into an R array of
  *  integers.
  *)

val floats_of_t : float list t -> float list
(**  Converts an R array of real numbers into a list of Objective
  *  Caml floats.
  *)

val float_of_t : float t -> float
(**  Converts an R array of floats with one element into an Objective
  *  Caml float.
  *)

val float : float -> float t
(**  Converts an Objective Caml float to an R real value, that is a
  *  mono-element array of real numbers.
  *)

val floats : float list -> float list t
(**  Converts a Objective Caml list of floats into an R array of
  *  real numbers.
  *)

val strings_of_t : string list t -> string list
(**  Converts an R array of strings into a list of Objective Caml
  *  strings.
  *)

val string_of_t : string t -> string
(**  Converts an R array of strings with one element into an Objective
  *  Caml string.
  *)

val string : string -> string t
(**  Converts an Objective Caml string to an R string, that is a
  *  mono-element array of strings.
  *)

val strings : string list -> string list t
(**  Converts an Objective Caml list of strings into an R array of
  *  strings.
  *)

val sexps_of_t : sexp list t -> sexp list
(**  Converts an R array of SEXPs into an Objective Caml list of
  *  SEXPs.
  *)
