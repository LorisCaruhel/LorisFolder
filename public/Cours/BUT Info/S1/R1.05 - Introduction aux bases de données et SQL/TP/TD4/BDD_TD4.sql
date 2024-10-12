alter table fourniture
  add constraint fourniture_fk_produit
  foreign key(noproduit) references produit(noproduit);
