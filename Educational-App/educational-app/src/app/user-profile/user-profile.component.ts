import { Component, OnInit } from '@angular/core';
import { User } from '../user';
import { PROFILES } from '../mock-users';



@Component({
  selector: 'app-user-profile',
  templateUrl: './user-profile.component.html',
  styleUrls: ['./user-profile.component.css']
})
export class UserProfileComponent implements OnInit {

users = PROFILES;
selectedUser?: User;


  constructor() {}
  ngOnInit() {
  }


  onSelect(user: User): void {
  this.selectedUser = user;
}
}
