class Main inherits A2I {
  main(): Object {
    (new IO).out_string(
        i2a(
          fibNumber(
            a2i((new IO).in_string()),
            0,
            1
          )
        ).concat("\n")
    )
  };

  fibNumber(i: Int, a: Int, b: Int): Int {
    if 
     i = 0
    then
     a 
    else
     fibNumber(i - 1, b, a+b) fi
  };
};
