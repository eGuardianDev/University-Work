import csv
import hashlib

input_file = "sanctions.csv"
output_file = "sanctions_hashed.csv"
size_of_hash = 12

def hash_value(text):
    if text is None:
        return ""
    text = text.strip()
    #return hashlib.sha256(text.encode("utf-8")).hexdigest()
    return hashlib.sha1(text.encode("utf-8")).hexdigest()

with open(input_file, "r", encoding="utf-8") as infile, \
     open(output_file, "w", encoding="utf-8", newline="") as outfile:

    reader = csv.DictReader(infile)
    fieldnames = reader.fieldnames.copy()

    # Optional: add a new column instead of replacing
    # fieldnames.append("Субстанция_Хеш")

    writer = csv.DictWriter(outfile, fieldnames=fieldnames)
    writer.writeheader()

    for row in reader:
        original = row["Субстанция"]
        row["Субстанция"] = hash_value(original) # overwrite with hash
        writer.writerow(row)

print("Done! New file saved as:", output_file)

