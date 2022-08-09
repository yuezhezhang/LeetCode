## [If + else if + else in one line](https://stackoverflow.com/questions/46540099/c-if-else-if-else-in-one-line)
  The format is `if_condition ? if_expression : elseif_condition ? elseif_expression : else_expression`
  ```
  int current_angle = 10;
  current_angle = (current_angle >= 180) ? current_angle - 360 : (current_angle < -180) ? current_angle + 360 : current_angle;
  ```
