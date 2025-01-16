(* 參考江子文同學的 感謝他的大恩大德 *)

open A
let buffer_of_string s = { text = s; current = 0; last = -1 }

module StringSet = Set.Make(String)
exception Break

let recognize s =
  let buffer = buffer_of_string s in
  let seen_tokens = ref StringSet.empty in
  let pre_last = ref 0 in
  try
    while true do
      buffer.last <- -1;
      start buffer;
      if buffer.last <> -1 then begin
        let token_length = buffer.last - !pre_last in
        let token = String.sub buffer.text !pre_last token_length in
        if not (StringSet.mem token !seen_tokens) then begin
          Printf.printf "--> \"%s\"\n" token;
          seen_tokens := StringSet.add token !seen_tokens
        end;
        if buffer.last = !pre_last then begin
          Printf.printf "would now loop\n";
          raise Break
        end;
        pre_last := buffer.last;
      end;
      buffer.current <- buffer.last;
      if buffer.last >= String.length buffer.text then raise Break
    done
  with
  | End_of_file -> ()
  | Break -> ()
  | Failure msg -> Printf.printf "exception %s\n" msg

let () =
  Printf.printf "請輸入一個字符串: ";
  let input_string = read_line () in 
  recognize input_string