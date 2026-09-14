use std::fmt::Write;

fn main() {
    let mut buf = String::new();
    std::io::stdin().read_line(&mut buf).unwrap();
    let num: i32 = buf.trim().parse().unwrap();
    match num {
        1 => println!("1"),
        2..=3 => println!("NO SOLUTION"),
        _ => {
            let mut buf = String::with_capacity(num as usize * 6);
            for i in (2..=num).step_by(2) {
                write!(&mut buf, "{} ", i).unwrap();
            }
            for i in (1..=num).step_by(2) {
                write!(&mut buf, "{} ", i).unwrap();
            }
            buf.pop();
            println!("{buf}");
        }
    }
}
