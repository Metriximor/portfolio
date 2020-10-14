use std::io;
use chrono::{Datelike, Utc};

fn get_current_year() -> u32 {
    let now = Utc::now();
    now.year() as u32
}

fn main() {
    let mut input = String::new();
    println!("What is your name?");
    let mut name = String::new();
    match io::stdin().read_line(&mut input) {
        Ok(_) => {
            name = input.trim().to_string();
            input.clear();
        }
        Err(_) => {
            println!("Error reading name, assuming default name");
            name = "Joe".to_string();
        }
    }
    println!("What is your age?");
    let mut age: u32 = 20;
    match io::stdin().read_line(&mut input) {
        Ok(_) => {
            match input.trim().parse() {
                Ok(a) => {
                    age = a;
                }
                Err(_) => {
                    println!("Failed to parse age, assuming default age");
                }
            }
        }
        Err(_) => {
            println!("Error reading age");
        }
    }
    let age_to_hundred = 100 - age as i32;
    if age_to_hundred > 0 {
        println!("Hello {}, you will be 100 years old in {}", name, age_to_hundred+get_current_year() as i32);
    } else {
        println!("Hello {}, you were 100 years old in {}", name, age_to_hundred+get_current_year() as i32);
    }
}
