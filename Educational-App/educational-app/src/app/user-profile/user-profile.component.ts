import { Component, OnInit } from '@angular/core';
import { User } from '../user';
import { PROFILES } from '../mock-users';
import { UserService } from '../user.service';
import { MessageService } from '../message.service';



@Component({
  selector: 'app-user-profile',
  templateUrl: './user-profile.component.html',
  styleUrls: ['./user-profile.component.css']
})
export class UserProfileComponent implements OnInit {

users: User[] = [];

selectedUser?: User;


  constructor(private userService: UserService, private messageService: MessageService) {}

  ngOnInit() {
  this.getUsers();
  }

  getUsers(): void {
    this.userService.getUsers()
   .subscribe(users => this.users = users);
  }

}
