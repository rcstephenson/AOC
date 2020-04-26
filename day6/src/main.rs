// Day 6 Advent of Code
// Part. 1 - 25 April 2020
use std::fs::File;
use std::process;
use csv;

type Record = (String, String); // Data Type for "object)orbit"

fn main() {
	let data: Vec<Record>;
	match run("input.txt") {
		Ok(out) => {
			data = out.clone();
		}
		Err(err) => {
			println!("{}", err);
			process::exit(1);
		}
	}
	let mut obj = Vec::new();
	let mut orb = Vec::new();
	for d in &data {
		obj.push(&d.0);
		orb.push(&d.1);
	}
	let mut sol = 0i32;
	for x in orb {
		let i = get_chain_len(x, &data, 0i32);
		sol += i;
	}
	println!("Part 1: {}",sol);
	
	println!("Part 2: {}", 0); //400~450
}

fn run(fname: &str) -> Result<Vec<Record>,csv::Error>{
    let f = File::open(fname).expect("Unable to open file");
	let mut rdr = csv::ReaderBuilder::new()
		.delimiter(b')')
		.has_headers(false)
		.from_reader(f);
	let mut out: Vec<Record> = Vec::new();
	for result in rdr.deserialize() {
		let record: Record = result?;
		out.push(record);	
	}
	Ok(out)
}

fn get_chain_len(orb: &str, map: &Vec<Record>, i: i32) -> i32 {
	if "COM"==orb {
		i
	} else {
		for mass in map {
			if mass.1 == orb {
				if i==0 {
					return get_chain_len(&mass.0, &map, 1);
				} else {
					return get_chain_len(&mass.0, &map,i+1);
				}
			}
		}
		-1
	}
}
