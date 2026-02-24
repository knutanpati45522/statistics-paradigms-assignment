(* OCaml (Functional) Statistics Calculator *)

let values = [4; 1; 2; 2; 3; 4; 5; 4; 2; 6; 7; 2; 4]

let mean lst =
  let sum = List.fold_left ( + ) 0 lst in
  float_of_int sum /. float_of_int (List.length lst)

let sorted lst = List.sort compare lst

let median lst =
  let s = sorted lst in
  let n = List.length s in
  if n mod 2 = 1 then
    float_of_int (List.nth s (n / 2))
  else
    let a = List.nth s ((n / 2) - 1) in
    let b = List.nth s (n / 2) in
    float_of_int (a + b) /. 2.0

let frequencies lst =
  List.fold_left
    (fun acc x ->
      let count = try List.assoc x acc with Not_found -> 0 in
      (x, count + 1) :: List.remove_assoc x acc)
    [] lst

let mode lst =
  let freq = frequencies lst in
  let max_count = List.fold_left (fun m (_, c) -> max m c) 0 freq in
  if max_count <= 1 then
    ([], max_count)
  else
    let modes =
      freq
      |> List.filter (fun (_, c) -> c = max_count)
      |> List.map fst
      |> List.sort compare
    in
    (modes, max_count)

let string_of_int_list lst =
  "[" ^ String.concat "; " (List.map string_of_int lst) ^ "]"

let string_of_modes modes =
  String.concat ", " (List.map string_of_int modes)

let () =
  Printf.printf "OCaml (Functional) Statistics Calculator\n";
  Printf.printf "Input values: %s\n" (string_of_int_list values);
  Printf.printf "Mean: %.2f\n" (mean values);
  Printf.printf "Median: %.2f\n" (median values);
  let modes, freq = mode values in
  match modes with
  | [] -> Printf.printf "Mode: No mode (all values occur once)\n"
  | _ -> Printf.printf "Mode(s): %s (frequency = %d)\n" (string_of_modes modes) freq
